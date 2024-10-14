class CaesarCipher {
    constructor(shift) {
        this.shift = shift % 26; 
    }

    encrypt(plaintext) {
        let encrypted = "";
        for (let char of plaintext) {
            if (/[a-zA-Z]/.test(char)) {
                const base = char === char.toLowerCase() ? 'a' : 'A';
                encrypted += String.fromCharCode(((char.charCodeAt(0) - base.charCodeAt(0) + this.shift) % 26) + base.charCodeAt(0));
            } else {
                encrypted += char; 
            }
        }
        return encrypted;
    }

    decrypt(ciphertext) {
        let decrypted = "";
        for (let char of ciphertext) {
            if (/[a-zA-Z]/.test(char)) {
                const base = char === char.toLowerCase() ? 'a' : 'A';
                decrypted += String.fromCharCode(((char.charCodeAt(0) - base.charCodeAt(0) - this.shift + 26) % 26) + base.charCodeAt(0));
            } else {
                decrypted += char; 
            }
        }
        return decrypted;
    }
}

const text = prompt("Enter text:");
const shift = parseInt(prompt("Enter shift value:"));

const cipher = new CaesarCipher(shift);
const encrypted = cipher.encrypt(text);
const decrypted = cipher.decrypt(encrypted);

alert(`Encrypted text: ${encrypted}`);
alert(`Decrypted text: ${decrypted}`);
