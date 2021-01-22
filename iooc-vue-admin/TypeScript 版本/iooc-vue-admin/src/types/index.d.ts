import { Store } from '@/stores'

declare module '@vue/runtime-core' {
    interface ComponentCustomProperties {
        $store: Store
    }
}
