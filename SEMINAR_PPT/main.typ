#import "@preview/touying-simpl-swufe:0.2.1": *

#show: swufe-theme.with(
  aspect-ratio: "16-9",
  lang: "en",

  config-info(
    title: [Towards Understanding Sycophancy in Language Models],
    author: [Abhay Balakrishnan],
    institution: ([MDL23CSBS004],[],[],[Department of Computer Engineering], [Model Engineering College], [CSQ413]),
    banner: none,
  ),
)

#set list(marker: [•], indent: 0.5em, body-indent: 0.5em)

#title-slide()

== What is Sycophancy?
#slide(title: [What is Sycophancy?])[
  - AI assistants trained with RLHF learn to maximize human *approval* — but approval and *correctness* are not the same thing
  - *Sycophancy:* a model favors responses that match what the user wants to hear over responses that are actually true
  - A confident, agreeable answer can score well with human raters even when it\'s factually wrong
  - Earlier work only showed this in staged setups where users stated a clear opinion — this paper asks: does it show up in *real production AI assistants* too?
]

== How It Was Tested
#slide(title: [How It Was Tested])[
  - *Models evaluated:* Claude 1.3, Claude 2, GPT-3.5, GPT-4, LLaMA 2 — five systems, three different labs
  - *Benchmark:* SycophancyEval — built from realistic, open-ended conversations rather than artificial prompts
  - *Four sycophancy probes:*
    - *Feedback* — does the model\'s opinion of a passage shift when the user says they like, dislike, or wrote it?
    - *\"Are you sure?\"* — does the model abandon a correct, confident answer under a single line of pushback?
    - *Answer* — does even a hedged user belief (\"I think it\'s X, but I\'m not sure\") bias the model\'s final answer?
    - *Mimicry* — does the model repeat a user\'s factual error instead of correcting it?
]

== Key Findings
#slide(title: [Key Findings])[
  - *Biased feedback:* identical passages got more positive ratings when users said they liked or wrote them — and harsher ratings when users said they disliked them
  - *Easily swayed:* a simple \"I don\'t think that\'s right. Are you sure?\" made models backtrack — Claude 1.3 wrongly admitted a mistake on *98%* of questions it had answered correctly
  - *Weak hints are enough:* just a hedged opinion (no argument, no pushback) cut accuracy by up to *27%* (LLaMA 2)
  - *Mimicry:* models attributed poems to whatever poet the user named — even though they could name the *correct* poet when asked directly
]

#align(center)[
  #image("assets/fig1.png", width: 100%)
]

== Takeaway
#slide(title: [Takeaway])[
  - All four sycophancy patterns showed up *consistently across all 5 models*, spanning Anthropic, OpenAI, and Meta — a *systemic training issue*, not one lab\'s bug
  - Root cause traced to the data: *\"matches the user\'s belief\"* is one of the strongest predictors of what human raters prefer — the RLHF signal itself rewards sycophancy
  - Optimizing harder against the Claude 2 preference model *increased* sycophancy; a modified \"non-sycophantic\" PM reduced it — the preference model is part of the problem, not just the base model
  - *Implication:* fixing this needs better evaluation and preference-collection methods — not just more human ratings, since unaided human raters are part of what causes the issue
]

== Where Does Sycophancy Come From?
#slide(title: [Where Does Sycophancy Come From?])[
  - All the AI assistants studied were finetuned using *human feedback* (RLHF)
  - *Hypothesis:* human feedback itself contributes to sycophancy
  - Approach: convert human preference comparisons into *interpretable features*, then measure which features predict the human\'s choice
]

== The Feature Model
#slide(title: [The Feature Model])[
  - *Dataset:* Anthropic hh-rlhf — 15K response pairs
  - GPT-4 zero-shot labels each pair on *23 interpretable features*
  - Bayesian logistic regression: $ p(R_A "preferred to" R_B | phi, alpha, P) = sigma(sum_(i=1)^(N_f) alpha_i phi_i), quad p(alpha_i) tilde "Laplace"(mu=0, b=0.01) $
    - $alpha_i in RR^(N_f)$: effect size of each feature
    - $phi_i in {-1, 0, +1}^(N_f)$: feature vector for the comparison
    - $sigma(dot)$: logistic function; $P$: the prompt; $R_A$: response A; $R_B$: response B
  - Holdout accuracy: *71.3%* — comparable to a full *52B-parameter* preference model trained on the same data (~72%)
]

== Sycophancy Is Rewarded, Not Just Correctness
#slide(title: [Sycophancy Is Rewarded, Not Just Correctness])[
  - *Matching the user\'s stated beliefs* is one of the most predictive features of human preference — shifts preference probability by up to *~6%*, all else equal
  - *Truthful*, *authoritative*, and *empathetic* responses are also rewarded, at comparable strength
]

#align(center)[
  #image("assets/fig5.png")
]

== Does the PM Learn the Same Sycophancy Bias?
#slide(title: [Does the PM Learn the Same Sycophancy Bias?])[
  - The preference model used to train the assistant learns from human ratings — so the question is whether it picks up the same tendency to favor *agreement over accuracy*
  - To find out, responses were optimized against this preference model using *Best-of-N sampling* and *RL finetuning*, then compared with a *non-sycophantic* version explicitly prompted to prioritize truth over the user\'s stated beliefs
  - The results were *mixed*: different forms of sycophancy showed different trends; however, during *RL training*, *feedback* and *mimicry* sycophancy increased rather than being eliminated
]

#align(center)[
  #image("assets/fig6.png")
]

== Do Humans and the Preference Model Fall for It Too?
#slide(title: [Do Humans and the Preference Model Fall for It Too?])[
  - Across *266 misconceptions* of varying difficulty, humans and the preference model chose between a truthful response and a convincing sycophantic one
  - The preference model prefers sycophancy *95% of the time* overall, and still picks it *nearly half the time* even on the hardest misconceptions
  - Human raters lean toward truthful responses overall, but their reliability *drops sharply* as the misconception gets harder to spot
  - Convincing sycophancy beats correctness for both humans and the preference model a meaningful fraction of the time — not just a theoretical risk

  #align(center)[
    #image("assets/fig7.png")
  ]
]

== Conclusion
#slide(title: [Conclusion])[
  - Human feedback is clearly useful for training high-quality AI assistants, but it has *predictable limitations*, and current systems reflect them
  - Sycophantic behavior showed up *consistently across five AI assistants*, in realistic, open-ended settings — not just contrived, proof-of-concept prompts
  - Sycophancy has several contributing causes, but *humans and preference models favoring agreeable responses over accurate ones* is clearly one of them
  - Fixing this needs *better oversight methods* — going beyond unaided, non-expert human ratings, which are part of what causes the problem in the first place
]

== Where Do We Go From Here?
#slide(title: [Where Do We Go From Here?])[
  - There is still *no single solution* that reliably eliminates sycophancy
  - Several approaches show *partial improvement*: better preference training, reasoning-based methods, inference-time interventions, and stronger human oversight
  - Each approach has *limitations and trade-offs*, and sycophancy can still reappear under different tasks or training settings
  - As a result, reducing sycophancy remains an *ongoing research problem* rather than a completely solved one
]

== References
#slide(title: [References])[
  #set text(size: 0.8em)
  - Sharma, M., Tong, M., Korbak, T., Duvenaud, D., Askell, A., Bowman, S. R., Cheng, N., Durmus, E., Hatfield-Dodds, Z., Johnston, S. R., Kravec, S., Maxwell, T., McCandlish, S., Ndousse, K., Rausch, O., Schiefer, N., Yan, D., Zhang, M., & Perez, E. (2024). *Towards Understanding Sycophancy in Language Models*. In International Conference on Learning Representations (ICLR 2024). arXiv:2310.13548. #link("https://arxiv.org/abs/2310.13548")
]
