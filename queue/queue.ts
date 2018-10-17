export class Queue<T> {

    length: number

    constructor(private _array: T[] = []) {
        this.length = _array.length
    }

    offer(element: T): void {
        this.length++
        this._array.push(element)
    }

    poll() {
        if (!this._isEmpty) {
            return this._array.splice(1)[0]
        }
        throw new Error('Queue is empty');
    }

    peek() {
        if (!this._isEmpty) {
            return this._array[0]
        }
        throw new Error('Queue is empty');
    }



    private _isEmpty(): boolean {
        return this.length == 0
    }
}