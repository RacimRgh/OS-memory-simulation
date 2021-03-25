#include "../headers/process.h"

// Memory first_fit(Memory m, Process p)
// {
//     while (m && (m->data.state == 'U' || m->data.size < p.size))
//         m = m->next;
//     return m;
// }

// Memory best_fit(Memory m, Process p)
// {
//     Memory r = first_fit(m, p);
//     m = r;
//     while (m)
//     {
//         if (m->data.state == 'F' && m->data.size >= p.size && m->data.size < r->data.size)
//             r = m;
//         m = m->next;
//     }
//     return r;
// }

// Memory worst_fit(Memory m, Process p)
// {
//     Memory r = first_fit(m, p);
//     m = r;
//     while (m)
//     {
//         if (m->data.state == 'F' && m->data.size >= p.size && m->data.size > r->data.size)
//             r = m;
//         m = m->next;
//     }
//     return r;
// }
