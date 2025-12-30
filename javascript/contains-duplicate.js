function containsDuplicate(array) {
    const seenNumbers = new Set()

    for (let i = 0; i < array.length; i++) {
        if (seenNumbers.has(array[i])) {
            return true;
        } else {
            seenNumbers.add(array[i]);
        }
    }

    return false;
}

console.log(containsDuplicate([2, 44234, 12, 2, 0, -123]))