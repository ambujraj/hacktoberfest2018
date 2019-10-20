void setup() {
  // put your setup code here, to run once:
  int arr[] = {5, 8, 10, 3, 2};
  for (int i = 0; i < sizeof(arr); i++) {
    for (int j = 0; j < sizeof(arr) - 1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp; 
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
