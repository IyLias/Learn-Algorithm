#from __future__ import annotations // code for python ver 2.*
from typing import TypeVar,Iterable,Sequence,Generic,List,Callable,Set,Deque,Dict,Any,Optional
from typing_extensions import Protocol
from heapq import heappush, heappop


T = TypeVar('T')

def linear_contains(iterable: Iterable[T], key:T) -> bool:
    for item in iterable:
        if key == item:
            return True
    return False


C = TypeVar("C",bound="Comparable")

class Comparable(Protocol):
    def __eq__(self,other: Any) -> bool:
        ...
    def __lt__(self: C,other: C) -> bool:
        ...
    def __gt__(self: C,other: C) -> bool:
        return (not self < other) and self!=other
    def __le__(self: C,other: C) -> bool:
        return self < other or self==other

    def __ge__(self: C, other: C) -> bool:
        return not self < other


def binary_contains(sequence: Sequence[C],key:C) -> bool:
    low:int = 0
    high:int = len(sequence) - 1
    while low <= high:
        mid:int = (low+high) // 2
        if sequence[mid] == key:
            return True
        elif sequence[mid] > key:
            high = mid - 1
        else:
            low = mid + 1
    return False


if __name__ == "__main__":
    print(linear_contains([1,5,10,15],10))
    print(binary_contains(['a','c','e','h'],'h'))
