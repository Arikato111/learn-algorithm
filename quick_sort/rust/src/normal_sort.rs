/**
 * this function can make stack overflow
 */
pub fn normal_quick_sort(arr: &mut [u32]) {
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
        normal_quick_sort(&mut arr[0..k as usize]);
    }
    if len2 > 1 {
        normal_quick_sort(&mut arr[(k + 1) as usize..]);
    }
}
