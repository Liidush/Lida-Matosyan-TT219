class GCD {
    constructor(a, b) {
        this.a = a;
        this.b = b;
    }

    computeGCD() {
        let a = this.a;
        let b = this.b;

        while (b !== 0) {
            let temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}

// Taking input from the user
const a = parseInt(prompt("Enter the first integer: "));
const b = parseInt(prompt("Enter the second integer: "));

const gcdCalculator = new GCD(a, b);
const result = gcdCalculator.computeGCD();

alert(`GCD of ${a} and ${b} is: ${result}`);
