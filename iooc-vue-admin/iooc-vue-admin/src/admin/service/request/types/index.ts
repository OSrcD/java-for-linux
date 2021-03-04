export * from './user';

export type Method = 'GET' | 'POST' | 'PUT' | 'DELETE' | 'PATCH'
export type ResponseType = 'arraybuffer' | 'blob' | 'document' | 'json' | 'text' | 'stream'

export interface AxiosRequest {
    baseURL?: string;
    url: string;
    data?: object;
    params?: object;
    method?: Method;
    headers?: object;
    timeout?: number;
    responseType?: ResponseType;
    onUploadProgress?: any
}

export interface AxiosResponse {
    data: any;
    headers: object;
    request?: object;
    status: number;
    statusText: string;
    config: AxiosRequest;
}

export interface CustomResponse {
    host?: any;
    readonly status: boolean;
    readonly message: string;
    data: any;
    origin?: any;
}
