use crate::sort::quick_sort_node;

pub fn quick_sort_normal(arr: &mut [u32]) {
    let arr_len = arr.len();
    let mut works = vec![[0, arr_len]];
    while let Some(w) = works.pop() {
        let (r1, r2) = quick_sort_node(arr, w[0], w[1]);
        if r1[0] != r1[1] {
            works.push(r1);
        }
        if r2[0] != r2[1] {
            works.push(r2);
        }
    }
}
/**
 * this function can make stack overflow
 */
pub fn quick_sort_recursive(arr: &mut [u32]) {
    let len = arr.len();
    let mut k: i32 = -1;
    for i in 0..len {
        if arr[i] <= arr[len - 1] {
            k += 1;
            if i as i32 > k {
                (arr[i], arr[k as usize]) = (arr[k as usize], arr[i]);
            }
        }
    }

    let len2 = len as i32 - k - 1;
    if k > 1 {
        quick_sort_recursive(&mut arr[0..k as usize]);
    }
    if len2 > 1 {
        quick_sort_recursive(&mut arr[(k + 1) as usize..]);
    }
}
