export class LinkedList<T> {

    public length: number

    constructor(private _array: T[] = []) {
        this.length = _array.length
    }

    clear(): void {
        this.length = 0
        this._array = []
    }

    clone(): LinkedList<T> {
        return new LinkedList(this._array)
    }

    set(index: number, element: T): T {
        const store = this._array[index];
        this._array[index] = element
        return store
    }

    contains(element: T): boolean {
        if (this._array.find(value => value == element)) {
            return true
        }
        return false
    }

    addAll(elements: T[]) {
        this.length += elements.length;
        this._array.push(...elements)
    }

    addAllAtIndex(index: number, elements: T[]) {
        this.length += elements.length;
        this._array.splice(index, 0, ...elements)
    }


    addAtIndex(index: number, element: T) {
        this.length++
        this._array.splice(index, 0, element)
    }

    add(element: T) {
        this.length++
        this._array.push(element)
    }

    addLast(element: T) {
        this.length++
        this.add(element)
    }

    addFirst(element: T) {
        this.length++
        this.addAtIndex(0, element)
    }

    get(index: number) {
        return this._array[index]
    }

    indexOf(element: T) {
        return this._array.indexOf(element)
    }

    lastIndexOf(element: T) {
        return this._array.lastIndexOf(element)
    }

    getFirst() {
        return this._array[0];
    }

    getLast() {
        return this._array[this.length - 1]
    }

    remove(index?: number) {
        this.length--
        if (index) {
            this._array.splice(index)
        }
        return this._array.splice(0)
    }

    removeElement(element: T) {
        const index = this._array.indexOf(element);
        return this.remove(index);
    }

    removeLast() {
        return this.remove(this.length - 1)
    }



}