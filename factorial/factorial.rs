fn factorial_recursive (n: u64) -> u64 {
    match n {
        0 => 1,
        _ => n * factorial_recursive(n-1)
    }
}
 
 
fn main () {
    for i in 1..10 {
        println!("{}", factorial_recursive(i))
    }
}
