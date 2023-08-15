Calculator
-----------

The "Calculator" program is a simple command-line application designed to perform basic arithmetic calculations. It allows users to perform addition, subtraction, multiplication, and division operations on multiple numbers at once, utilizing the convenience of vectors for input.

Functionality:
1. User chooses an arithmetic operation (+, -, *, /).
2. User enters the number of input values.
3. Program collects input values and stores them in a vector.
4. Program processes input values based on the chosen operation.
5. Final result of the operation is displayed.

Advantages:
1. Modularity: Each arithmetic operation is encapsulated in a function within the "Calculator" class.
2. Reusability: Encapsulated operations are reusable in other projects or code.
3. Simplicity: Straightforward structure for educational purposes.
4. Flexibility: Easily expandable for new operations.
5. Efficient Multi-Number Input: Process sequences of numbers at once using a vector for example {1+2+3+4+5+5} or {4-4-5-2-3-6-4}.
6. Basic Error Handling: Limited error handling to handle invalid input.

Disadvantages:
1. Limited Error Handling: Doesn't cover all error scenarios.
2. Command-Line Interface: Lacks graphical user interface.
3. No Memory of Previous Calculations: No memory for result chaining (e.g., 2 + 3 * 4)..
4. Limited Validation: Limited input validation for accuracy.


