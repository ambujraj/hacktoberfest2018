export class Stack<T> {

    length: number;

    constructor(private _array: T[] = []) {
        this.length = _array.length;
    }

    peek(): T {
        if (!this._isEmpty) {
            return this._array[this.length - 1]
        }
        throw new Error('Stack is empty');
    }

    pop(): T {
        if (!this._isEmpty) {
            this.length--
            return this._array.pop()
        }
        throw new Error('Stack is empty');
    }

    push(element: T): void {
        this.length++
        this._array.push(element)
    }

    private _isEmpty(): boolean {
        return this.length == 0
    }

}