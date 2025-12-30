const name: string = "Henrique";
const age: number = 25;
const isStudent: boolean = false;

function greet(name: string): string {
    const msg: string = `Hello, ${name}!`;
    console.log(msg);
    return msg;
}

function proclaim(status?: string, repeat: number = 0) {
    let actualStatus = status ?? "Success";
    for (let i = 0; i < repeat + 1; i++) {
        console.log(actualStatus);
    }
}

const hobbies: string[] = ["eat", "read", "code"];

interface User {
    id: number,
    username: string,
    email?: string,
    childAccounts?: User[]
};

function logUser(user: User): void {
    for (const [k, v] of Object.entries(user) as [keyof User, (string | number)][]) {
        console.log(`${k}: ${v}`);
    }
}

type Coordinate = readonly [number, number];
const coord: Coordinate = [1, 2];
console.log(coord)

function formatValue(val: string | number) {
    if (typeof val === 'string') {
        console.log(`${val} is a string.`);
        return;
    }

    console.log(`${val} is a number.`)
}

enum Status {
    SUCCESS = 1,
    PENDING,
    FAILED
};

const status: Status = Status.PENDING;

function identity<T extends {length: number}>(thing: T): T {
    console.log(`The identity of the thing is: ${typeof thing}`);
    return thing;
}

class StorageContainer<T> {
    private itemList: T[] = [];

    addItem(item: T) {
        this.itemList.push(item);
    }

    getItem(index: number) {
        return this.itemList[index];
    }

    deleteItem(index: number) {
        this.itemList.splice(index, 1);
    }
}

function logUserPartial(user: Partial<User>) {
    for (const [k, v] of Object.entries(user) as [keyof User, string | number | undefined][]) {
        console.log(`${k}: ${v}`);
    }
}

async function fetchData<T>(url: string): Promise<T> {
    const response = await fetch(url);
    const data: T = await response.json();
    return data;
}

async function checkUserStatus<T>(user: User): Promise<Partial<T>> {
    const response = await fetch('')
    const data: Partial<T> = await response.json()
    return data
}

type RequiredUser<User> = Required<User>

type RequiredUser2 = {
    [K in keyof User]-?: User[K]
} 

type Finalized<T> = Readonly<T>;

type Finalized2<T> = {
    readonly [K in keyof T]: T[K] extends object ? Finalized2<T[K]> : T[K]
}

const finalizedObj: Finalized2<User> = {
    id: 1,
    username: 'h',
    email: 'h@gmail.com',
    childAccounts: [
        {
            id: 2,
            username: 'ab',
        }
    ]
}

type OnlyString<T> = {
    [K in keyof T as T[K] extends string ? K : never]: T[K]
}

export { }