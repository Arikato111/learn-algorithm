use rand::Rng;
use std::{
    sync::{Arc, Mutex},
    time::Instant,
};
#[allow(unused)]
use thread_sort::{normal_sort::normal_quick_sort, sort::quick_sort};

const ARR_LEN: usize = 100_000_000;
fn main() {
    let mut random = rand::thread_rng();
    let arr = Arc::new(Mutex::new(vec![0u32; ARR_LEN]));
    for i in 0..ARR_LEN {
        /*
         *  arr.lock().unwrap()[i] = random.gen::<u8>() as u32;
         *  gen with u8 and change to u32 make it slower.
         */
        arr.lock().unwrap()[i] = random.gen::<u32>();
    }
    let s1 = Instant::now(); // time counter
    // quick_sort(&arr, 4);
    quick_sort(&arr, 4);
    /*
     * array 10^8 elements.
     * quick sort 1 thread: 10s
     * quick sort 16 thread: 11s
     */
    println!("{:?}", s1.elapsed());
    // println!("{:?}", arr.lock().unwrap());
}
