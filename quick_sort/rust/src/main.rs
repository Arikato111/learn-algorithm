#[allow(unused)]
use thread_sort::{normal_sort::normal_quick_sort, sort::quick_sort};
use rand::Rng;
use std::{
    sync::{Arc, Mutex},
    time::Instant,
};

const ARR_LEN: usize = 10_000_000;
fn main() {
    let mut random = rand::thread_rng();
    let arr = Arc::new(Mutex::new(vec![0u32; ARR_LEN]));
    for i in 0..ARR_LEN {
        arr.lock().unwrap()[i] = random.gen::<u8>() as u32;
    }
    // quick_sort_node(&mut arr, 0, arr_len);
    // println!("{:?}", arr.lock().unwrap());
    let s1 = Instant::now();
    // 0 is 62
    // quick_sort(&arr, 4); // 1839.10849619s
    quick_sort(&arr, 0);  // 1892.023405653s
    // let a = arr.clone();
    // normal_quick_sort(&mut a.lock().unwrap());
    println!("{:?}", s1.elapsed());
    // println!("{:?}", arr.lock().unwrap());
}
