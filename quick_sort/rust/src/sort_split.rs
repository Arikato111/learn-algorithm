/*
* เนื่องจากการใช้ multi thread แบบเดิมนั้นช้า โดยคาดคะเนว่ามาจากการแชร์ตัวแปรร่วมกัน
* เลยคิดว่าจะแบ่ง array ให้แต่ละ thread เป็นของใครของมันเลย แล้วค่อยนำมารวมกันทีหลัง
*
*/
use std::thread::{self, JoinHandle};

pub fn quick_sort_node(arr: &mut [u32], st: usize) -> ([usize; 2], [usize; 2]) {
    let mut k = -1;
    let arr_len = arr.len();
    for i in 0..arr_len {
        if arr[i] <= arr[arr_len - 1] {
            k += 1;
            (arr[i], arr[k as usize]) = (arr[k as usize], arr[i]);
        }
    }
    let len2 = arr_len as i32 - k - 1;
    (
        if k > 1 { [st, st + k as usize] } else { [0, 0] },
        if len2 > 1 {
            [(st + k as usize + 1) as usize, st + arr_len]
        } else {
            [0, 0]
        },
    )
}

pub fn quick_sort(arr: &mut Vec<u32>) {
    let works = vec![[0, arr.len() / 2], [arr.len() / 2 + 1, arr.len()]];
    let mut thread_list: Vec<JoinHandle<(usize, Vec<u32>)>> = vec![];
    for w in works {
        let mut a = arr[w[0]..w[1]].to_vec();
        let t = thread::spawn(move || {
            let th_id = thread::current().id();
            println!("thread start");
            let mut works = vec![[0, a.len()]];
            loop {
                println!("{:?} working", th_id);
                let wk = works.get(0).unwrap();
                let (r1, r2) = quick_sort_node(a[wk[0]..wk[1]].as_mut(), wk[0]);
                if r1[0] != r1[1] {
                    works.push(r1);
                }
                if r2[0] != r2[1] {
                    works.push(r2);
                }

                works.remove(0);
                if works.len() == 0 {
                    break;
                }
            }
            println!("thread end");
            (w[0], a.to_owned())
        });
        thread_list.push(t);
    }
    for th in thread_list {
        let (idx, arr_result) = th.join().unwrap();
        for i in 0..arr_result.len() {
            arr[idx + i] = arr_result[i];
        }
    }
}
