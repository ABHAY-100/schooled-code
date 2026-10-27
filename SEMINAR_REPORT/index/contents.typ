#set page(
  paper: "a4",
  margin: (left: 1.5cm, right: 1.5cm, top: 4cm, bottom: 3cm)
)

#set text(
  font: "New Computer Modern",
  size: 13pt
)

#set par(
  justify: true,
  leading: 0.7em
)

#set heading(numbering: "1.1")

#show heading.where(level: 2): it => block(above: 1.6em, below: 0.9em)[#it]
#show heading.where(level: 3): it => block(above: 1em, below: 0.6em)[#it]

#show heading.where(level: 1): it => block(width: 100%, below: 3em)[
  #align(center)[
    #text(size: 17pt, weight: "bold")[Chapter #counter(heading).display("1")]
    #v(-0.2cm)
    #text(size: 21pt, weight: "bold")[#it.body]
  ]
]

#align(center)[
  #text(size: 21pt, weight: "bold")[Contents]
]

#v(1.4cm)

#outline(
  title: none,
  indent: 1em,
  depth: 3
)

#include "list_of_figures.typ"
#include "list_of_tables.typ"

#set page(numbering: "1")
#counter(page).update(1)

#set page(
  header: context {
    let loc = here()
    let pageHeads = query(heading.where(level: 1)).filter(h => h.location().page() == loc.page())
    // if pageHeads.len() > 0 {
    //   none
    // } else {
      set text(size: 11pt, fill: black)
      let heads = query(heading.where(level: 1)).filter(h => h.location().page() <= loc.page())
      let title = if heads.len() > 0 { heads.last().body } else { [] }
      let num = if heads.len() > 0 { counter(heading).at(heads.last().location()).first() } else { [] }
      v(0.6em)
      grid(
        columns: (1fr),
        align(center)[Towards Understanding Sycophancy in Language Models],
        // align(right)[Chapter #num \ #title],
      )
      v(1.8em)
      // line(length: 100%, stroke: 0.4pt + black)
      v(0.6em)
    // }
  },
  footer: context {
    let loc = here()
    let pageHeads = query(heading.where(level: 1)).filter(h => h.location().page() == loc.page())
    // if pageHeads.len() > 0 {
    //   set text(size: 11pt, fill: black)
    //   align(center)[#counter(page).display()]
    // } else {
      set text(size: 11pt, fill: black)
      v(0.6em)
      // line(length: 100%, stroke: 0.4pt + black)
      v(0.8em)
      grid(
        columns: (1fr, auto),
        align(left)[Dept. of Computer Engineering, MEC, 2026],
        align(right)[#counter(page).display()],
      )
      v(0.6em)
    // }
  },
)

#include "../chapters/ch_1.typ"

#pagebreak()
#include "../chapters/ch_2.typ"

#pagebreak()
#include "../chapters/ch_3.typ"

#pagebreak()
#include "../chapters/ch_4.typ"

#pagebreak()
#include "../chapters/ch_5.typ"

#pagebreak()
#include "../chapters/ch_6.typ"

#pagebreak()
#include "../chapters/ch_7.typ"

#pagebreak()
#include "../chapters/ch_8.typ"

#pagebreak()
#include "../other/references.typ"
