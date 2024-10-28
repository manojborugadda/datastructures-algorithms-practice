// https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1?page=2&category=Recursion&company=Microsoft&sortBy=difficulty


class Solution {
  public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long count=0;
    void TOHhelperFunc(int N, int from, int to, int aux) {
    if(N > 0) {
    toh(N-1,from,aux,to);
    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
    count++;
    toh(N-1,aux,to,from);
}

}
long long toh(int N, int from, int to, int aux) {
    TOHhelperFunc(N,from,to,aux);
    return count;
}

};
