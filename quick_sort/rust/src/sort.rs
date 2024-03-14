use std::{
    sync::{Arc, Mutex},
    thread::{self, JoinHandle},
};

pub fn quick_sort_node(arr: &mut [u32], st: usize, ed: usize) -> ([usize; 2], [usize; 2]) {
    let mut k = st as i32 - 1;
    for i in st..ed {
        if arr[i] <= arr[ed - 1] {
            k += 1;
            (arr[i], arr[k as usize]) = (arr[k as usize], arr[i]);
        }
    }
    let len2 = ed as i32 - k - 1;
    (
        if k > 1 { [st, k as usize] } else { [0, 0] },
        if len2 > 1 {
            [(k + 1) as usize, ed]
        } else {
            [0, 0]
        },
    )
}

fn quick_sort_linear(arr_ch: Arc<Mutex<Vec<u32>>>, init_work: [usize; 2]) {
    let mut work_n = vec![init_work];
    let arr_clone = arr_ch.clone();
    let mut arr = arr_clone.lock().unwrap();
    while let Some(w) = work_n.pop() {
        let (r1, r2) = quick_sort_node(&mut arr, w[0], w[1]);
        if r1[0] != r1[1] {
            work_n.push(r1);
        }
        if r2[0] != r2[1] {
            work_n.push(r2);
        }
    }
}

pub fn quick_sort(arr: &Arc<Mutex<Vec<u32>>>, thread: u32) {
    let arr_ch = arr.clone();
    let len = arr_ch.lock().unwrap().len();
    let works = Arc::new(Mutex::from(vec![[0, len]]));
    let work = works.clone();
    let mut thread_list: Vec<JoinHandle<()>> = vec![];

    // prepare works for thread
    for _ in 0..thread {
        while let Some(w) = works.lock().unwrap().pop() {
            thread_list.push(quick_sort_thread(arr, &works, w));
        }
        while let Some(th) = thread_list.pop() {
            th.join().unwrap();
        }
    }
    println!("thread: {}", works.lock().unwrap().len());
    // prepare thread
    while let Some(w) = work.lock().unwrap().pop() {
        let a = arr_ch.clone();
        let t = thread::spawn(move || {
            println!("thread start");
            quick_sort_linear(a, w);
            println!("thread end: {}/{}", w[0], w[1]);
        });
        thread_list.push(t);
    }

    // run thread
    for th in thread_list {
        th.join().unwrap();
    }
}

fn quick_sort_thread(
    arr: &Arc<Mutex<Vec<u32>>>,
    works: &Arc<Mutex<Vec<[usize; 2]>>>,
    w: [usize; 2],
) -> JoinHandle<()> {
    let work_th = works.clone();
    let ar = arr.clone();
    let t = thread::spawn(move || {
        let mut arr = ar.lock().unwrap();
        let (r1, r2) = quick_sort_node(&mut arr, w[0], w[1]);
        if r1[0] != r1[1] {
            work_th.lock().unwrap().push(r1);
        }
        if r2[0] != r2[1] {
            work_th.lock().unwrap().push(r2);
        }
    });
    t
}
