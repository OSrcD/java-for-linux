import {store, Store} from "@/store";

export function useStore(): Store {
    return store as Store
}