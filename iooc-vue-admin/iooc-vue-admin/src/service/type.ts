export interface UserProps {
    username: string;
    password: string;
    captchaId: string;
    verifyCode: string;
}

export interface CaptchaProps {
    height: number;
    width: number;
}