/**
 * @param {string} path
 * @returns {Boolean}
 */
export function isExternal(path: string): boolean {
    return /^(https?:|mailto:|tel:)/.test(path)
}

/**
 * @param {string} str
 * @returns {Boolean}
 */
export function validUsername(str: string): boolean {
    const valid_map = ['admin', 'editor']
    return valid_map.indexOf(str.trim()) >= 0
}
