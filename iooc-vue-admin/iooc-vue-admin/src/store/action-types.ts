import {ActionTypes as MenuActionTypes} from "@/store/menu/type/action-types"
import {ActionTypes as UserActionTypes} from "@/store/user/type/action-types"


export const AllActionTypes = { ...MenuActionTypes, ...UserActionTypes };