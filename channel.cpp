#include "channel.hpp"

namespace gsc {

// Channel::Channel() : closed(false) {}
template<typename T>
T Channel<T>::get(bool wait) {
  std::unique_lock<std::mutex> lock(m);

  if (wait) {
    cv.wait(lock, [&]() {
      return closed || !queue.empty();
    });
  }

  if (closed) {
    throw std::logic_error(ERROR_GET_FROM_CLOSED_QUEUE);
  }

  T out = queue.front();
  queue.pop_front();
  return out;
}

template<typename T>
void Channel<T>::put(T elem) {
  std::unique_lock<std::mutex> lock(m);
  if (closed) {
    throw std::logic_error(ERROR_PUT_TO_CLOSED_QUEUE);
  }
  queue.push_back(elem);
  cv.notify_one();
}

}