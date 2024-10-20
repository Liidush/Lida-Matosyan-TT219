function runLengthEncoding(input) {
    let encoded = "";
    const n = input.length;

    for (let i = 0; i < n; i++) {
        let count = 1;
        while (i < n - 1 && input[i] === input[i + 1]) {
            count++;
            i++;
        }
        encoded += input[i];
        encoded += count.toString();
    }

    return encoded;
}





























function runLengthDecoding(encoded) {
    let decoded = "";
    const n = encoded.length;

    for (let i = 0; i < n; i++) {
        const currentChar = encoded[i];
        i++;
        const count = parseInt(encoded[i], 10);

        for (let j = 0; j < count; j++) {
            decoded += currentChar;
        }
    }

    return decoded;
}


const input = prompt("Enter the string to be encoded:");
const encoded = runLengthEncoding(input);
console.log("Encoded string:", encoded);

const decoded = runLengthDecoding(encoded);
console.log("Decoded string:", decoded);
