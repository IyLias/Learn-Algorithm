from typing import TypeVar, Generic , List
T = TypeVar('T')

class Stack(Generic[T]):

    def __init__(self) -> None:
        self._container:List[T] = []

    def push(self,item: T) -> None:
        self._container.append(item)

    def pop(self) -> T:
        return self._container.pop()

    def __repr__(self) -> str:
        return repr(self._container)


def print_tower() -> None:
    
    print("process start..")

    print(tower_a)
    print(tower_b)
    print(tower_c)

    print("process end..")


def move_disk(start : Stack[int],via:Stack[int], dest : Stack[int]) -> None:

    disk: int = start.pop()
    dest.push(disk)
    print_tower()


def hanoi_process(start: Stack[int],via: Stack[int],dest: Stack[int],num: int) -> None:
    
    if num > 0:
       hanoi_process(start,dest,via,num-1)
       move_disk(start,via,dest)
       hanoi_process(via,start,dest,num-1)


num_discs: int = 4

tower_a:Stack[int] = Stack()
tower_b:Stack[int] = Stack()
tower_c:Stack[int] = Stack()

for i in range(1,num_discs+1):
    tower_a.push(i)


hanoi_process(tower_a,tower_b,tower_c,num_discs)

