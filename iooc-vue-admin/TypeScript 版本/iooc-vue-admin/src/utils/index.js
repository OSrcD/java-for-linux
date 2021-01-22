
export function isArray(value) {
    if (typeof Array.isArray === "function") {
        return Array.isArray(value);
    } else {
        return Object.prototype.toString.call(value) === "[object Array]";
    }
}

export function isObject(value) {
    return Object.prototype.toString.call(value) === "[object Object]";
}

export function isNumber(value) {
    return !isNaN(Number(value));
}

export function isFunction(value) {
    return typeof value == "function";
}

export function isString(value) {
    return typeof value == "string";
}

export function isEmpty(value) {
    if (isArray(value)) {
        return value.length === 0;
    }

    if (isObject(value)) {
        return Object.keys(value).length === 0;
    }

    return value === "" || value === undefined || value === null;
}
