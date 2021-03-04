import IconSvg from "./icon-svg";
import Avatar from "./avatar"
import ContextMenu from "./context-menu"
import Code from "./code";
import DeptCheck from "./dept/check.vue";
import DeptTree from "./dept/tree.vue";
import DeptMove from "./dept/move.vue";
import Distpicker from "./distpicker";
import MenuIcons from "./menu/icons.vue";
import MenuTree from "./menu/tree.vue";
import MenuPerms from "./menu/perms.vue";
import MenuFilePath from "./menu/file-path.vue";
import RoleTree from "./role/tree.vue";
import RoleSelect from "./role/select.vue";
import UploadNext from "./upload";
import UploadSpaceNext from "./upload";

export default function (app) {
    app.component("icon-svg", IconSvg);
    app.component("io-avatar", Avatar);
    app.component("io-context-menu", ContextMenu);
    app.component("io-code", Code);
    app.component("io-dept-check", DeptCheck);
    app.component("io-dept-tree", DeptTree);
    app.component("io-dept-move", DeptMove);
    app.component("io-distpicker", Distpicker);
    app.component("io-menu-icons", MenuIcons);
    app.component("io-menu-tree", MenuTree);
    app.component("io-menu-perms", MenuPerms);
    app.component("io-menu-file-path", MenuFilePath);
    app.component("io-role-tree", RoleTree);
    app.component("io-role-select", RoleSelect);
    app.component("io-upload", UploadNext);
    app.component("io-upload-space", UploadSpaceNext);
}
