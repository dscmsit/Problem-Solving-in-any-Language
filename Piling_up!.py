# There is a horizontal row of n cubes. The length of each cube is given. You need to create a new vertical pile of cubes. The new pile should follow these directions: if cube[i] is on top of cube[j] then sideLength[j] >= sideLenght[i].

# When stacking the cubes, you can only pick up either the leftmost or the rightmost cube each time. Print Yes if it is possible to stack the cubes. Otherwise, print No.

test_cases = int(input())

while(test_cases > 0):
    
    n = int(input())
    sides = input().split()
    sides_list = []
    for side in sides:
        sides_list.append(int(side))
    top = 0
    vertical_stack = []
    i = 0
    j = len(sides_list) - 1
    if(sides_list[i] > sides_list[j]):
        vertical_stack.append(sides_list[i])
        i += 1
    elif(sides_list[i] <= sides_list[j]):
        vertical_stack.append(sides_list[j])
        j -= 1
    result = ''
    while(i <= j):
        result = 'Yes'
        if(sides_list[i] <= vertical_stack[top] and sides_list[j] <= vertical_stack[top]):
            if(sides_list[i] > sides_list[j]):
                vertical_stack.append(sides_list[i])
                top += 1
                i += 1
            else:
                vertical_stack.append(sides_list[j])
                top += 1
                j -= 1
        elif(sides_list[i] <= vertical_stack[top]):
            vertical_stack.append(sides_list[i])
            top += 1
            i += 1
        elif(sides_list[j] <= vertical_stack[top]):
            vertical_stack.append(sides_list[j])
            top += 1
            j -= 1
        else:
            result = 'No'   
            break
    print(result)
    test_cases -= 1  
