import path from "path";

export default function ({store}) {
    const files = require.context("@/service/", true, /\.ts$/);
    const ignore = ["./request.ts", "./type.ts"];

    let modules = {};

    files
        .keys()
        .filter((e) => !ignore.includes(e))
        .map((e) => {
            if (e.includes("--ignore")) {
                return false;
            }

            let list = e.substr(2).split("/");
            let parents = list.slice(0, list.length - 1);
            let name = path.basename(e, ".ts");

            let curr = modules;
            let prev = null;
            let key = null;

            parents.forEach((k) => {
                if (!curr[k]) {
                    curr[k] = {};
                }

                prev = curr;
                curr = curr[k];
                key = k;
            });

            let ep = files(e);

            if (ep.default) {
                let service = new ep.default();

                if (name == "index") {
                    prev[key] = service;
                } else {
                    curr[name] = service;
                }
            } else {
                console.error(`Service must export default [${e}]`);
            }
        });

    return modules
}
