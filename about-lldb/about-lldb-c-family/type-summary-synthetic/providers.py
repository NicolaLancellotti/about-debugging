from typing import Optional

import lldb


def RectangleSummaryProvider(valobj: lldb.SBValue, _):
    height = valobj.GetChildMemberWithName("height").GetValueAsUnsigned(0)
    width = valobj.GetChildMemberWithName("width").GetValueAsUnsigned(0)
    area = height * width
    perimeter = 2 * (height + width)
    return "Area: " + str(area) + ", Perimeter: " + str(perimeter)


class RectangleSyntheticChildrenProvider:
    def __init__(self, valobj: lldb.SBValue, _) -> None:
        self.valobj = valobj

    def num_children(self) -> int:
        return self.valobj.GetNumChildren()

    def get_child_index(self, name: str) -> int:
        if name == "height":
            return 0
        if name == "width":
            return 1
        return -1

    def get_child_at_index(self, index: int) -> Optional[lldb.SBValue]:
        if index == 0:
            return self.valobj.GetChildMemberWithName("height")
        if index == 1:
            return self.valobj.GetChildMemberWithName("width")
        return None


class RectanglePointerSyntheticChildrenProvider:
    def __init__(self, valobj: lldb.SBValue, _) -> None:
        self.valobj = valobj

    def num_children(self) -> int:
        return 0

    def get_child_index(self, name: str) -> int:
        if name == "$$dereference$$":
            return 0
        return -1

    def get_child_at_index(self, index: int) -> Optional[lldb.SBValue]:
        if index == 0:
            return self.valobj.GetChildMemberWithName("_pointer").Dereference()
        return None


class RectangleBoxSyntheticChildrenProvider:
    def __init__(self, valobj: lldb.SBValue, _) -> None:
        self.valobj = valobj

    def num_children(self) -> int:
        return 1

    def get_child_index(self, name: str) -> int:
        return -1

    def get_child_at_index(self, index: int) -> Optional[lldb.SBValue]:
        return self.valobj.GetChildMemberWithName("_pointer").Dereference()
