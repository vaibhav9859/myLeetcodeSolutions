class Solution {
  public String fractionAddition(String expression) {
    int first = 0;
    int second = 1;
    
    Scanner sc = new Scanner(expression).useDelimiter("/|(?=[+-])");

    for (;sc.hasNext();) {
      final int valA = sc.nextInt();
      final int valB = sc.nextInt();
      first = first * valB + valA * second;
      second *= valB;
      final int g = gcd(first, second);
      first /= g;
      second /= g;
    }

    return first + "/" + second;
  }

  private int gcd(int num1, int num2) {
    return num1 == 0 ? Math.abs(num2) : gcd(num2 % num1, num1);
  }
}
