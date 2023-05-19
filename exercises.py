def sum(arr):
    if len(arr) == 0:
        return 0
    elif len(arr) == 1:
        return arr[0]
    else:
        item = arr.pop(0)
        return item + sum(arr)
    

#print(sum([5,4,1,3]))


def counter(arr):
    counterInt = 0
    if len(arr) == 1:
        counterInt +=1
        return counterInt
    else:
        counterInt +=1
        arr.pop(0)
        return counterInt + counter(arr)
    
#print(counter([5,4,1,3,1,2,3,4,6]))


def getTheBiggerNumber(arr):
    print('arr',arr)
    if len(arr) == 1:
        return arr[0]
    else:
        item = arr.pop(0)
        bigger = getTheBiggerNumber(arr)
        if item > bigger:
            return item
        else:
            return bigger
 
        
print(getTheBiggerNumber([40,10,2,3,4,5]))