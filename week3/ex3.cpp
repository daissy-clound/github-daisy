Stack:
    T = null

Function push(value):
    Node newNode = new Node(value)
    newNode.next = T
    T = new_node

Function pop():
    if T == null:
        print("Stack Underflow")
        return
    T = T.next

Function peek():
    if T == null:
        print("Stack is empty")
        return null
    return T.value

Function isEmpty():
    return T == null
