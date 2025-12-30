// 1.
function fizzBuzz(n: number): void {
    for (let i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            console.log(`FizzBuzz`);
        } else if (i % 3 == 0) {
            console.log(`Fizz`);
        } else if (i % 5 == 0) {
            console.log(`Buzz`);
        }
    }
}

fizzBuzz(15);

// 2.
function isPalindrome(s: string): boolean {
    let reversedStringArr: string[] = new Array(s.length);

    for (let i = 0; i < s.length; i++) {
        reversedStringArr[i] = s[s.length - 1 - i];
    }

    let reversedString = reversedStringArr.join('');
    console.log(reversedString)
    return reversedString === s
}