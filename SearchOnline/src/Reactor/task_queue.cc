
#include "../../include/Reactor/task_queue.h"

namespace search_engine {

TaskQueue::TaskQueue(size_t queSize)
: _queSize(queSize),
  _que(),
  _mutex(),
  _notEmpty(_mutex),
  _notFull(_mutex),   
  _flag(true) { }



void TaskQueue::push(ElemType&& value) {
    MutexLockGuard autoLock(_mutex); // autoLock栈对象

    while (full()) {     // 防止虚假唤醒
        _notFull.wait();
    }

    _que.push(std::move(value));

    _notEmpty.notify();
}

ElemType TaskQueue::pop() {
    MutexLockGuard autoLock(_mutex); //autoLock栈对象

    while (empty() && _flag) {
        _notEmpty.wait();
    }

    if (_flag) {
        ElemType tmp  = _que.front();
        _que.pop();

        _notFull.notify();
        return tmp;
    } else {
        return nullptr;
    }
}

} // namespace search_engine
