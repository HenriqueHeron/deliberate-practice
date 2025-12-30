function twoSum(array, target) {
    const seenNumbers = {};
    for (let i = 0; i < array.length; i++) {
        const currentNumber = array[i];
        const diff = target - currentNumber;

        if (seenNumbers[diff] !== undefined) {
            const index = seenNumbers[diff];
            return [index, i];
        } else {
            seenNumbers[currentNumber] = i;
        }
    }

    return null;
}

console.log(twoSum([2, 5, 3, 8], 13))