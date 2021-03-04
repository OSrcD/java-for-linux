import {MutationTree} from 'vuex'
import {MutationTypes} from "./type/mutation-types"
import {ProcessListProps, ProcessStateTypes, ProcessMutations} from "@/store/interface"


export const mutations: MutationTree<ProcessStateTypes> & ProcessMutations = {
    [MutationTypes.ADD_PROCESS](state, payload: ProcessListProps) {
        const index = state.list.findIndex(
            (e) => {
                return e.value.split("?")[0] === payload.value.split("?")[0]
            }
        );
        state.list.map((e) => {
            e.active = e.value == payload.value;
        });

        if (index < 0) {
            if (payload.value == "/") {
                payload.label = "首页";
            }

            if (payload.label) {
                state.list.push({
                    ...payload,
                    active: true
                });
            }
        } else {
            state.list[index].active = true;
            state.list[index].label = payload.label;
            state.list[index].value = payload.value;
        }

    },
    [MutationTypes.DEL_PROCESS](state, index: number) {
        state.list.splice(index, 1)
    },
    [MutationTypes.SET_PROCESS](state, payload: ProcessListProps[]) {
        state.list = payload
    },
    [MutationTypes.RESET_PROCESS](state) {
        state.list = [
            {
                label: "首页",
                value: "/",
                active: true
            }
        ];
    }
}