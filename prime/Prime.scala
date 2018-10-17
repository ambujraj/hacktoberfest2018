package prime

object Fib {
  def fibGen(limit: Int): List[Int] = {
    (2 to limit).filter(num => !(2 until num).exists(num % _ == 0)).toList
  }
}
