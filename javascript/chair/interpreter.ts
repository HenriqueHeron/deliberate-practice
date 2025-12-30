import { isDigit } from "./utils/utils";


function evaluate(s: string) {
    const stack: (string | number)[] = [];
    const operationMap = {
        '+': () => {
            let val1 = stack.pop();
            let val2 = stack.pop();
        }
    };
    const tokens = s.split(' ');
    for (const token of tokens) {
        if (isDigit(token)) {
            stack.push(Number(token))    
        }


    }

}