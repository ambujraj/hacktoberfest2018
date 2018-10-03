public class RecursiveSingleLinkedListImpl<T> implements LinkedList<T> {

    protected T data;
    protected RecursiveSingleLinkedListImpl<T> next;

    public RecursiveSingleLinkedListImpl() {
        this(null, null);
    }

    public RecursiveSingleLinkedListImpl(T data, RecursiveSingleLinkedListImpl<T> next) {
        this.data = data;
        this.next = next;
    }

    @Override
    public boolean isEmpty() {
        return this.size() == 0;
    }

    @SuppressWarnings("unused")
    @Override
    public int size() {
        if (this.data != null) {
            int size = (this.next != null) ? 1 + this.next.size() : 1;
            return size;
        }
        return 0;
    }

    @Override
    public T search(T element) {
        if (element != null) {
            if (this.data == null || this.data.equals(element))
            return this.data;

            T searchValue = (this.next != null) ? this.next.search(element) : null;

            return searchValue;
        }

        return null;
    }

    @Override
    public void insert(T element) {
        if (element != null) {
            if (this.data == null)
            this.data = element;
            else if (this.next == null)
            this.next = new RecursiveSingleLinkedListImpl<>(element, null);
            else
            this.next.insert(element);
        }
    }

    @Override
    public void remove(T element) {
        if (element != null && !this.isEmpty() && this.data != null) {
            if (this.data.equals(element)) {
                if (this.next == null)
                this.data = null;
                else {
                    this.data = this.next.data;
                    this.next = this.next.next;
                }
            } else
            if (this.next != null)
            this.next.remove(element);
        }
    }

    @SuppressWarnings("unchecked")
    @Override
    public T[] toArray() {
        T[] array = (T[]) new Object[this.size()];

        int i = 0;
        RecursiveSingleLinkedListImpl<T> node = this;

        while (node != null && i < this.size()) {
            array[i] = node.data;
            node = node.next;
            i++;
        }

        return array;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public RecursiveSingleLinkedListImpl<T> getNext() {
        return next;
    }

    public void setNext(RecursiveSingleLinkedListImpl<T> next) {
        this.next = next;
    }

}
