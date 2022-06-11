import { log } from "./utils.js";
import category from "./category.js";
import { scm } from "./schema.js";
import queues from "./run-queue.js";

const compo = {
    _: new Map(),
    sto: null,

    /**
     * @param name
     * @param {string} name
     * @param info
     * @param {string} info
     * @param data
     * @param {object} data
     * @param pre
     * @param {Function} pre
     * @param func
     * @param {Function} func
     * @param styl
     * @param {string} styl
     * @returns {Function}
     */
    reg: (name, info, data, pre, func, styl) => {
        const sn = category.alias("component") + name;
        info = info.replaceAll(" ", "_");
        scm[sn] = {
            ty: "object",
            lvs: {
                on: { ty: "boolean", dft: true },
                ...data,
            },
        };
        compo._.set(name, { info, pre, styl });
        return (...args) => func(...((data ? [{ msto: compo.sto[sn] }] : []).concat(args)));
    },
};

queues.onload.push(() => {
    for (const [nm, co] of compo._.entries()) {
        if (co.styl) GM_addStyle(co.styl);
        log(`Preparing component: ${nm}`);
        if (co.pre) co.pre({ msto: compo.sto[category.alias("component") + nm] });
    }
});

export default compo;
