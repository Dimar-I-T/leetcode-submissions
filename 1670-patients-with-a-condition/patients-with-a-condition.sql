-- dimar's solution
select patient_id, patient_name, conditions
from patients
where conditions ~ '^DIAB1| DIAB1'
