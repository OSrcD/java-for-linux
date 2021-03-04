import {ComponentInternalInstance, getCurrentInstance} from "vue";

interface CommonProps {
    upload: (data?: any) => any;
    ossUpload: (data?: any) => any;
    ossSign: (data?: any) => any;
    userLogin: (userInfo: UserProps) => any;
    userLogout: (data?: any) => any;
    userInfo: (data?: any) => any;
    userUpdate: (data?: any) => any;
    permMenu: (data?: any) => any;
    captcha: (data?: any) => any;
}
interface CRUDProps {
    page: (data?: any) => any;
    list: (data?: any) => any;
    info: (data?: any) => any;
    add: (data?: any) => any;
    delete: (data?: any) => any;
    update: (data?: any) => any;
}
interface MenuProps {}
interface RoleProps {}

interface DeptProps {
    order: (data?: any) => any
}
interface UserProps {
    move: (data?: any) => any
}

interface SystemProps {
    menu: MenuProps & CRUDProps
    dept: CRUDProps & DeptProps
    user: CRUDProps & UserProps
    role: CRUDProps & RoleProps
}
interface ServiceProps {
    common: CommonProps,
    system: SystemProps,
}

export default function useService() : any {
    const instance = getCurrentInstance() as ComponentInternalInstance
    return instance.proxy?.$service
}