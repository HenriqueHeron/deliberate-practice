function _hash(str) {
    let hash = 0;
    const PRIME = 31;

    for (let i = 0; i < str.length; i++) {
        hash = (hash * PRIME + str[i].charCodeAt(0)) % str.length;
    }

    return hash;
}

function groupAnagrams(strArray) {
    const groups = new Array(strArray.length);

    for (let i = 0; i < strArray.length; i++) {
        let hash = _hash(strArray[i]);
        if (groups[hash] !== undefined) {
            groups[hash].push(strArray[i])
        } else {
            groups[hash] = [strArray[i]];
        }
    }

    return groups;
}

console.log(groupAnagrams(["cinema", "iceman", "race"]));