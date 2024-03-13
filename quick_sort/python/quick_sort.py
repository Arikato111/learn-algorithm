def quick_sort_node(arr: list, st: int, ed: int) -> list: 
    k = st - 1
    for i in range(st, ed):
        if arr[i] <= arr[ed - 1]:
            k += 1
            arr[i], arr[k] = arr[k], arr[i]
    len2 = ed -k -1
    result = []
    result.append([st, k] if k > 1 else [0, 0])
    result.append([k + 1, ed] if len2 > 1 else [0, 0])
    return result

def quick_sort_linear(arr: list, init_work: list):
    while len(init_work):
        w = init_work.pop()
        if w[0] == w[1]: continue
        [r1, r2] = quick_sort_node(arr, w[0], w[1])
        init_work.append(r1)
        init_work.append(r2)

def quick_sort(arr: list):
    quick_sort_linear(arr, [[0, len(arr)]])

