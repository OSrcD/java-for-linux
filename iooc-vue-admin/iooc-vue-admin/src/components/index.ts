import {App} from "vue"

import MenuTree from "./Menu/MenuTree/index.vue"
import MenuFilePath from "./Menu/MenuFilePath/index.vue"
import MenuIcons from "./Menu/MenuIcons/index.vue"
import MenuPerms from "./Menu/MenuPerms"
import DeptTree from "./Dept/tree.vue"
import ContextMenu from "./ContextMenu"
import Avatar from "./Avatar/index.vue"
import Upload from "./Upload/index.vue"
import RoleSelect from "./Role/select.vue"
import RoleTree from "./Role/tree.vue"
import Warning from "./Warning/index.vue"
import DeptMove from "./Dept/move"
import DeptCheck from "./Dept/check.vue"
import Transfer from "./Dept/transfer"
import Scrollbar from "./Scrollbar/index.vue"

const components = [
    MenuTree,
    MenuFilePath,
    MenuIcons,
    MenuPerms,
    ContextMenu,
    DeptTree,
    Avatar,
    Upload,
    RoleSelect,
    Warning,
    DeptMove,
    Transfer,
    RoleTree,
    DeptCheck,
    Scrollbar
]

const install = (app: App) => {
    components.forEach(component => {
        app.component(component.name, component);
    });
};

export {
    install
}