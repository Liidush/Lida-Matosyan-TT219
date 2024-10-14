class Program {
    constructor() {
        this.text = this.generateText();
        this.key = this.generateKey();
    }

    generateText() {
        let text = [];
        for (let i = 0; i < 26; i++) {
            text.push(String.fromCharCode('A'.charCodeAt(0) + i));
        }
        this.print(text);
        return text;
    }

    generateKey() {
        let key = [];
        for (let i = 0; i < 26; i++) {
            key.push(String.fromCharCode('Z'.charCodeAt(0) - i));
        }
        this.print(key);
        return key;
    }

    encrypt(word) {
        for (let i = 0; i < word.length; i++) {
            const index = this.text.indexOf(word[i]);
            if (index !== -1) {
                word[i] = this.key[index];
            }
        }
    }

    decrypt(word) {
        for (let i = 0; i < word.length; i++) {
            const index = this.key.indexOf(word[i]);
            if (index !== -1) {
                word[i] = this.text[index];
            }
        }
    }

    print(word) {
        alert(word.join(''));
    }
}


const p = new Program();

let word = ['Q', 'N', 'A', 'R'];
p.encrypt(word);
p.print(word); 
p.decrypt(word);
p.print(word); 
