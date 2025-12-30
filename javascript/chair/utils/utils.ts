function isDigit(char: string): boolean {
    return /^\d+$/.test(char);
}

export {isDigit}