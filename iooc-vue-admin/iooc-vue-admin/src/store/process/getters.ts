import {GetterTree} from 'vuex'
import {ProcessStateTypes, ProcessGettersTypes, IRootState} from '@/store/interface'

export const getters: GetterTree<ProcessStateTypes, IRootState> & ProcessGettersTypes = {
    processList: state => state.list
}