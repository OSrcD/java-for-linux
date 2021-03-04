import {MutationTypes as MenuMutationTypes} from "@/store/menu/type/mutation-types"
import {MutationTypes as ProcessMutationTypes} from "@/store/process/type/mutation-types"
import {MutationTypes as UserMutationTypes} from "@/store/user/type/mutation-types"


export const AllMutationTypes = {...MenuMutationTypes, ...ProcessMutationTypes, ...UserMutationTypes}